/*****************************************************************************
 *	EventArgs.h 															 *
 *																			 *
 *	System::EventArgs class definition file 								 *
 *	Copyright (c) XFX Team. All Rights Reserved 							 *
 *****************************************************************************/
#ifndef _SYSTEM_EVENTARGS_
#define _SYSTEM_EVENTARGS_

#include "Object.h"

namespace System
{
	/**
	 * EventArgs is the base class for classes containing event data.
	 */
	class EventArgs : public Object
	{
	public:
		static EventArgs * const Empty;

		EventArgs();
		virtual ~EventArgs() { }

		static const Type& GetType();
	};
}

#endif //_SYSTEM_EVENTARGS_
