#include <node.h>
#include "queue.h"

NAN_MODULE_INIT(InitAll) {
    NativeQueue::Queue::Init(target);
}

NODE_MODULE(Queue, InitAll)
