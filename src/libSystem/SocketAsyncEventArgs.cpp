#include <System/Net/Sockets/SocketAsyncEventArgs.h>

namespace System
{
	namespace Net
	{
		namespace Sockets
		{
			SocketAsyncEventArgs::SocketAsyncEventArgs()
			{
			}

			void SocketAsyncEventArgs::Dispose()
			{
			}
			
			void SocketAsyncEventArgs::Oncompleted(SocketAsyncEventArgs e)
			{
				if (Completed)
					Completed(this, e);
			}
		}
	}
}