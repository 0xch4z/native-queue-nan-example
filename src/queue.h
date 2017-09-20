#ifndef QUEUE_H
#define QUEUE_H

#include <nan.h>
#include "node.h"

namespace NativeQueue {

    class Queue: public Nan::ObjectWrap {
        // JS Methods
        static NAN_METHOD(New);
        static NAN_METHOD(Enqueue);
        static NAN_METHOD(Dequeue);
        static NAN_METHOD(Peek);
        // Native Properties
        node *_head;
        node *_tail;
        // Native Methods
        Queue(): _head(nullptr), _tail(nullptr) {}
        bool isEmpty();
    public:
        static NAN_MODULE_INIT(Init);
    };

}

#endif /* QUEUE_H */
