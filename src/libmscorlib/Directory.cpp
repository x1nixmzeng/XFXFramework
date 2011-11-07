// Copyright (C) 2010-2012, Halofreak_1990
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright 
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright 
//       notice, this list of conditions and the following disclaimer in the 
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the copyright holder nor the names of any 
//       contributors may be used to endorse or promote products derived from 
//       this software without specific prior written permission.
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

#include <System/DateTime.h>
#include <System/String.h>
#include <System/IO/Directory.h>
#include <System/IO/DirectoryInfo.h>
#include <System/IO/File.h>

#include <hal/fileio.h>

#if DEBUG
#include <stdio.h>
#endif

namespace System
{
	namespace IO
	{
		DirectoryInfo Directory::CreateDirectory(char* path)
		{
			if (path == null)
			{
#if DEBUG
				printf("ARGUMENT_NULL in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "path");
#endif
				return DirectoryInfo();
			}

			if (File::Exists(path))
			{
#if DEBUG
				printf("IO in function %s, at line %i in file %s: %s", __FUNCTION__, __LINE__, __FILE__, String::Format("Cannot create %s because a file with the same name already exists.\n", path));
#endif
				return DirectoryInfo();
			}

			XCreateDirectory(path);

			return DirectoryInfo(path);
		}

		void Directory::Delete(char* path)
		{
			Delete(path, false);
		}

		void Directory::Delete(char* path, bool recursive)
		{
			
		}

		bool Directory::Exists(char* path)
		{
			return File::Exists(path);
		}

		DateTime Directory::GetLastAccessTime(char* path)
		{
			return File::GetLastAccessTime(path);
		}

		DateTime Directory::GetLastWriteTime(char* path)
		{
			return File::GetLastWriteTime(path);
		}

		void Directory::Move(char* sourceDirName, char* destDirName)
		{
			File::Move(sourceDirName, destDirName);
		}
	}
}
