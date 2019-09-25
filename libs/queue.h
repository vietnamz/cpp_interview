

/*
 * Interview.h
 *
 *  Created on: Feb 23, 2019
 *      Author: delgemoon
 */

#ifndef LIBS_QUEUE_H_
#define LIBS_QUEUE_H_

#include <string>
#include <memory>
using namespace std;

template<typename T> class Queue {
    private:
        shared_ptr<T> head;
        size_t size = 5;
        size_t count = 0;
        size_t keep_incr = 1;
    public:
        Queue() {
            head = std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
        }
        explicit Queue(size_t N) {
            size = N;
            head = std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
        }
        void push(T new_element) {
            if ( count > size ) {
                keep_incr++;
                shared_ptr<T> new_head = std::shared_ptr<T>(new T[keep_incr * size], std::default_delete<T[]>());
                new_head = move(head);
                new_head.get()[count++] = new_element;
                head.reset();
                head = move(new_head);
            } else {
                head.get()[count++] = new_element;
            }
        }
        void pop() {
            if (count == 0 ) {
                throw invalid_argument("No element yet");
            }
            if (count == 1 ) {
                count = 0;
                return;
            }
            for(int i = 1; i < count; i++ ) {
                head.get()[i-1] = head.get()[i];
            }
            count--;
        }
        T front() {
            if ( count == 0 ) {
                throw invalid_argument("No element yet");
            }
            return head.get()[0];
        }
        void reset() {
            head.reset();
        }

        size_t get_size() {
            return count;
        }
};

#endif /* LIBS_INTERVIEW_H_ */
