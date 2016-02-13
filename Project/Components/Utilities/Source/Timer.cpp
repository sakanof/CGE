#include "..\include\Timer.h"

namespace Utilities
{
	namespace Timer
	{
		Timer::Timer(void)
			: m_hasBeenStarted(false),
			m_startTime(Time()),
			m_lastTime(Time()) { }
		Timer::~Timer(void) {}

		void Timer::Start()
		{
			if (!this->m_hasBeenStarted)
			{
				this->m_hasBeenStarted = true;
				this->m_startTime = std::chrono::high_resolution_clock::now();
				this->m_lastTime = this->m_startTime;
			}
		}

		bool Timer::IsRunning() const { return this->m_hasBeenStarted; }

		void Timer::Tick()
		{
			Time now = std::chrono::time_point<std::chrono::high_resolution_clock>(std::chrono::high_resolution_clock::now());
			this->m_elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(now - this->m_lastTime).count();
			this->m_lastTime = now;
		}

		void Timer::Reset()
		{
			this->m_startTime = std::chrono::high_resolution_clock::now();
			this->m_lastTime = this->m_startTime;
		}

		__int64 Timer::GetElapsedTimeInNanoSeconds() const { return this->m_elapsedTime; }

		__int64 Timer::GetElapsedTimeInMicroSeconds() const { return (__int64)(this->m_elapsedTime*0.001f); }

		__int64 Timer::GetElapsedTimeInMilliSeconds() const { return (__int64)(this->m_elapsedTime*0.000001f); }

		float Timer::GetElapsedTimeInSeconds() const { return (float)this->m_elapsedTime*0.000000001f; }

		__int64 Timer::GetElapsedTimeFromStart()
		{
			return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - this->m_startTime).count() / 1000000;
		}
	};
};