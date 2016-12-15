#include "../Include/Timer.h"

namespace Utilities
{
	namespace Timer
	{
		Timer::Timer(void)
			: m_startTime(Time()),
			m_lastTime(Time()),
			m_hasBeenStarted(false) { }
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

		int64_t Timer::GetElapsedTimeInNanoSeconds() const { return this->m_elapsedTime; }

		int64_t Timer::GetElapsedTimeInMicroSeconds() const { return (int64_t)(this->m_elapsedTime*0.001f); }

		int64_t Timer::GetElapsedTimeInMilliSeconds() const { return (int64_t)(this->m_elapsedTime*0.000001f); }

		float Timer::GetElapsedTimeInSeconds() const { return (float)this->m_elapsedTime*0.000000001f; }

		int64_t Timer::GetElapsedTimeFromStart()
		{
			return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - this->m_startTime).count() / 1000000;
		}
	};
};
