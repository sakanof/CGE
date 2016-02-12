#ifndef Utilities_Timer_H
#define Utilities_Timer_H

// standard Includes
#include <chrono>
#include <iostream>

// Util Includes
#include "UtilitiesSetup.h"

using std::chrono::time_point;
using std::chrono::system_clock;
using std::chrono::high_resolution_clock;

namespace Utilities
{
	namespace Timer
	{
		UTILITIES_EXP_TEMPLATE template class UTILITIES_API std::chrono::duration < std::chrono::system_clock::rep, std::chrono::system_clock::period > ;
		UTILITIES_EXP_TEMPLATE template class UTILITIES_API time_point < system_clock > ;

		class UTILITIES_API Timer
		{
			using Time = std::chrono::time_point < std::chrono::system_clock > ;
		private:
			__int64 m_elapsedTime;		/** < Elapsed time since the start of the timer. */
			Time	m_startTime;		/** < Keeps track of the time that the timer was started. */
			Time	m_lastTime;			/** < Keeps track of the last time that the timer has been updated. */
			bool	m_hasBeenStarted;	/** < Indicates if the timer has been initialized. */

		public:
			Timer(void);
			~Timer(void);

			/**
			*	\brief Starts the timer.
			**/
			void Start();

			/**
			*	\brief Returns true if the timer has been started and false if not.
			**/
			bool IsRunning() const;

			/**
			 *	\brief Updates the timer.
			 **/
			void Tick();

			/**
			 *	\brief Resets the start time of the timer.
			 **/
			void Reset();

			/**
			*	\brief Return the elapsed time since the last tick in nanoseconds.
			**/
			__int64 GetElapsedTimeInNanoSeconds() const;

			/**
			*	\brief Return the elapsed time since the last tick in microseconds.
			**/
			__int64 GetElapsedTimeInMicroSeconds() const;

			/**
			*	\brief Return the elapsed time since the last tick in milliseconds.
			**/
			__int64 GetElapsedTimeInMilliSeconds() const;

			/**
			*	\brief Return the elapsed time since the last tick in seconds.
			**/
			float GetElapsedTimeInSeconds() const;

			/**
			 *	\brief Return the elapsed time, in milliseconds, from the start of the timer until now.
			 **/
			__int64 GetElapsedTimeFromStart();
		};
	};
};

#endif // Utilities_Timer_H