/********************************************************
 *	Guide.h												*
 *														*
 *	XFX Guide definition file							*
 *	Copyright � XFX Team. All Rights Reserved			*
 ********************************************************/
#ifndef _XFX_GAMERSERVICES_GUIDE_
#define _XFX_GAMERSERVICES_GUIDE_

#include <System/Collections/Generic/Interfaces.h>
#include <System/Delegates.h>
#include <System/Interfaces.h>
#include <System/TimeSpan.h>
#include <System/Types.h>
#include <Storage/StorageDevice.h>
#include "Enums.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace XFX::Storage;

namespace XFX
{
	namespace GamerServices
	{
		/// <summary>
		/// Provides access to the Guide user interface.
		/// </summary>
		class Guide
		{
		private:
			static bool _isVisible;

			// Private constructor to prevent instantiation
			Guide();

		public:
			static bool IsScreenSaverEnabled;
			static bool IsVisible();
			static NotificationPosition_t NotificationPosition;

			static IAsyncResult* BeginShowKeyboardInput(PlayerIndex_t player, char* title, char* description, char* defaultText, AsyncCallback callback, Object* state);
			static IAsyncResult* BeginShowMessageBox(PlayerIndex_t player, char* title, char* text, IEnumerable<char*>* buttons, int focusButton, MessageBoxIcon_t icon, AsyncCallback callback, Object* state);
			static IAsyncResult* BeginShowStorageDeviceSelector(int sizeInBytes, int directoryCount, AsyncCallback callback, Object* state);
			static IAsyncResult* BeginShowStorageDeviceSelector(AsyncCallback callback, Object* state);
			static IAsyncResult* BeginShowStorageDeviceSelector(PlayerIndex_t player, int sizeInBytes, int directoryCount, AsyncCallback callback, Object* state);
			static IAsyncResult* BeginShowStorageDeviceSelector(PlayerIndex_t player, AsyncCallback callback, Object* state);
			static void DelayNotifications(TimeSpan timespan);
			static char* EndShowKeyboardInput(IAsyncResult* result);
			static int EndShowMessageBox(IAsyncResult* result);
			static StorageDevice EndShowStorageDeviceSelector(IAsyncResult* result);
		};
	}
}

#endif //_XFX_GAMERSERVICES_GUIDE_
