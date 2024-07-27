
#ifndef EASY_LOG_NOCOPYABLE_H
#define EASY_LOG_NOCOPYABLE_H

namespace Log::Base
{
    class NoCopyAbled
    {
    public:
        NoCopyAbled() = default;

        NoCopyAbled(const NoCopyAbled&) = delete;

        NoCopyAbled(NoCopyAbled&&) = delete;

        NoCopyAbled& operator=(const NoCopyAbled&) = delete;

        void operator=(NoCopyAbled&&) = delete;
    };
}

#endif
