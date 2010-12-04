// Copyright (C) 2010-2012, XFX Team
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
//* Redistributions of source code must retain the above copyright 
//notice, this list of conditions and the following disclaimer.
//* Redistributions in binary form must reproduce the above copyright 
//notice, this list of conditions and the following disclaimer in the 
//documentation and/or other materials provided with the distribution.
//* Neither the name of the copyright holder nor the names of any 
//contributors may be used to endorse or promote products derived from 
//this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.

#include <System/IO/File.h>
#include <System/IO/FileStream.h>
#include <System/IO/IOException.h>
#include <System/IO/Path.h>
#include <Content/ContentLoadException.h>
#include <Content/ContentManager.h>
#include <Content/ContentReader.h>

#include <string.h>

#if ENABLE_XBOX
extern "C" {
#include <xboxkrnl/xboxkrnl.h>
}
#else

#endif

using namespace System;

namespace XFX
{
	namespace Content
	{	
		ContentManager::ContentManager()
		{
			RootDirectory = "";
		}

		ContentManager::ContentManager(char* rootDirectory)
		{
			if(rootDirectory == null)
				throw ArgumentNullException("'rootDirectory' cannot be NULL.");

			RootDirectory = rootDirectory;
		}

		ContentManager::~ContentManager()
		{
			Dispose(false);
		}

		void ContentManager::Dispose(bool disposing)
		{
			if (!disposed)
			{
				if (disposing)
				{
					// Dispose any managed resources
					Unload();
				}
				// Dispose any unmanaged resources
				disposed = true;
			}  
		}

		void ContentManager::Dispose()
		{
			Dispose(true);
		}
		
		template <class T>
		T ContentManager::Load(char* assetName)
		{	
			/* TODO: port the C# code below to C++
			 object obj2;
			if (this.loadedAssets == null)
			{
				throw new ObjectDisposedException(this.ToString());
			}
			if (string.IsNullOrEmpty(assetName))
			{
				throw new ArgumentNullException("assetName");
			}
			assetName = GetCleanPath(assetName);
			if (this.loadedAssets.TryGetValue(assetName, out obj2))
			{
				if (!(obj2 is T))
				{
					throw new ContentLoadException(string.Format(CultureInfo.CurrentCulture, FrameworkResources.BadXnbWrongType, new object[] { assetName, obj2.GetType(), typeof(T) }));
				}
				return (T) obj2;
			}
			T local = this.ReadAsset<T>(assetName, null);
			this.loadedAssets.Add(assetName, local);
			return local;
			*/
		}

		Stream ContentManager::OpenStream(char* assetName)
		{
			Stream stream;
			try
			{
				int len = strlen(assetName);

				if (assetName[len-4] != '.')
				{
					//! XNA-style assetName, huh? Then it must be an .xnb file.
					char* path = Path::Combine(RootDirectory, strcat(assetName, ".xnb"));
					stream = File::OpenRead(path);
				}
				else
				{
					//! just a normal, for example, .png file
					stream = File::OpenRead(assetName);
				}
			}
			catch(FileNotFoundException fileNotFound)
			{
				throw ContentLoadException("The content file was not found.", fileNotFound);
			}
			catch(DirectoryNotFoundException directoryNotFound)
			{
				throw ContentLoadException("The directory was not found.", directoryNotFound);
			}
			catch(Exception exception)
			{
				throw ContentLoadException("Error opening stream.", exception);
			}
			return stream;
		}

		template <class T>
		T ContentManager::ReadAsset(char* assetName)
		{
			if(disposed)
				throw ObjectDisposedException("ContentManager");

			if (assetName == "" || assetName == null)
				throw ArgumentNullException("assetName");

			Stream assetStream = OpenStream(assetName);
			
			ContentReader reader = ContentReader(this, assetStream, assetName);
			
			return reader.ReadAsset<T>();
		}

		void ContentManager::Unload()
		{
			if(disposed)
				throw ObjectDisposedException("ContentManager");

			for(int i = 0; i < disposableAssets.Count(); i++)
			{
				disposableAssets[i].Dispose();
			}
			//loadedAssets.Clear();
			disposableAssets.Clear();
		}
	}
}