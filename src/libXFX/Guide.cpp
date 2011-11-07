// Copyright (C) 2010-2012, XFX Team
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

#include <GamerServices/Guide.h>
#include <GamerServices/StorageDeviceAsyncResult.h>
#include <System/TimeSpan.h>

#if DEBUG
#include <stdio.h>
#endif

namespace XFX
{
	namespace GamerServices
	{
		bool Guide::IsVisible()
		{
			return _isVisible;
		}

		IAsyncResult* Guide::BeginShowKeyboardInput(PlayerIndex_t player, char *title, char *description, char *defaultText, AsyncCallback callback, Object* state)
		{
			if (!title)
				title = "";

			if (!description)
				description = "";

			if (!defaultText)
				defaultText = "";

			// just return null to stop warning until this thing's coded
			return null;
		}

		IAsyncResult* Guide::BeginShowMessageBox(PlayerIndex_t player, char* title, char* text, IEnumerable<char*>* buttons, int focusButton, MessageBoxIcon_t icon, AsyncCallback callback, Object* state)
		{
			// just return null to stop warning until this thing's coded
			return null;
		}

		IAsyncResult* Guide::BeginShowStorageDeviceSelector(int sizeInBytes, int directoryCount, AsyncCallback callback, Object* state)
		{
			// just return null to stop warning until this thing's coded
			return null;
		}

		IAsyncResult* Guide::BeginShowStorageDeviceSelector(AsyncCallback callback, Object* state)
		{
			// just return null to stop warning until this thing's coded
			return null;
		}

		IAsyncResult* Guide::BeginShowStorageDeviceSelector(PlayerIndex_t player, int sizeInBytes, int directoryCount, AsyncCallback callback, Object* state)
		{
			// just return null to stop warning until this thing's coded
			return null;
		}

		IAsyncResult* Guide::BeginShowStorageDeviceSelector(PlayerIndex_t player, AsyncCallback callback, Object* state)
		{
			// just return null to stop warning until this thing's coded
			return null;
		}

		char* Guide::EndShowKeyboardInput(IAsyncResult* result)
		{
			// just return an empty string to stop warning until this thing's coded
			return "";
		}

		int Guide::EndShowMessageBox(IAsyncResult* result)
		{
			// Since C++ doesn't have a nullable type, we return -1, since it represents an invalid value anyways.
			return -1;
		}

		StorageDevice Guide::EndShowStorageDeviceSelector(IAsyncResult* asyncResult)
		{
			StorageDeviceAsyncResult* result = (StorageDeviceAsyncResult*)asyncResult;
			if (!result)
			{
#if DEBUG
				printf("ARGUMENT_NULL in function %s, at line %i in file %s, argument \"%s\"\n", __FUNCTION__, __LINE__, __FILE__, "result");
#endif
			}
			return StorageDevice(0, (PlayerIndex_t)result->playerIndex);
		}
	}
}
