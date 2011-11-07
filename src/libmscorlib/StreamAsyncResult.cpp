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

#include <System/IO/StreamAsyncResult.h>

namespace System
{
	namespace IO
	{
		StreamAsyncResult::StreamAsyncResult(Object* state)
		{
			_nbytes = -1;
			_state = state;
		}

		StreamAsyncResult::StreamAsyncResult(const IAsyncResult &obj)
		{
			_nbytes = -1;
		}

		StreamAsyncResult::StreamAsyncResult(const StreamAsyncResult &obj)
		{
			_nbytes = -1;
			_state = obj._state;
			completed = obj.completed;
			done = obj.done;
			//exc = obj.exc;
		}

		Object* StreamAsyncResult::AsyncState()
		{
			return _state;
		}

		bool StreamAsyncResult::CompletedSynchronously()
		{
			return true;
		}

		/*Exception* StreamAsyncResult::getException()
		{
			return exc;
		}*/

		bool StreamAsyncResult::IsCompleted()
		{
			return completed;
		}

		int StreamAsyncResult::NBytes()
		{
			return _nbytes;
		}

		Threading::WaitHandle* StreamAsyncResult::AsyncWaitHandle()
		{
			return null;
		}

		/*void StreamAsyncResult::SetComplete(Exception* e)
		{
			exc = e;
			completed = true;
			
			lock(this)
			{
				if(wh)
					wh.Set();
			}
			
		}

		void StreamAsyncResult::SetComplete(Exception* e, int nbytes)
		{
			_nbytes = nbytes;
			SetComplete(e);
		}*/
	}
}
