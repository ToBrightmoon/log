#ifndef MESSAGE_BUFFER
#define MESSAGE_BUFFER

#include <array>
#include <utility>
#include <iostream>

#include "nocopyable.h"

namespace Log
{
    namespace Base
    {
        template <class T,std::size_t Capacity>
        class Buffer : NoCopyAbled
        {
            using Buffer_T = Buffer<T,Capacity>;
            using BufferIterator = typename std::array<T,Capacity>::iterator;

        public:
            explicit Buffer() = default;

            [[nodiscard]] bool isFull() const noexcept
            {
                return size() == Capacity;
            }

            [[nodiscard]] int size() const noexcept
            {
                return curr_size_;
;           }

            bool add(const T& element) noexcept
            {
                if(isFull())
                {
                    return false;
                }else
                {
                    buffer_.at(curr_size_++) = element;
                    return true;
                }
            }

            [[nodiscard]] int maxCapacity() const noexcept
            {
                return buffer_.size();
            }

            void transData(Buffer_T& other) noexcept
            {
                std::move(other.begin(),other.end(),this->begin());
                other.clear();
            }

            const T& operator[](int index) const
            {
                return buffer_[index];
            }

            const T& at(int index) const noexcept
            {
               return buffer_.at(index);
            }

        private:

            BufferIterator begin() noexcept
            {
                return buffer_.begin();
            }

            BufferIterator end() noexcept
            {
                return buffer_.end();
            }

            void clear()
            {
                buffer_.fill(T());
                curr_size_ = 0;
            }

        private:
            int curr_size_ = 0;
            std::array<T,Capacity> buffer_;
        };
    }
}

#endif