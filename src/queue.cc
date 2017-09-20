#include "queue.h"

NAN_METHOD(NativeQueue::Queue::New) {
    if (!info.IsConstructCall()) {
        // prefer instance with identifier
        Nan::ThrowError("assign to an identifier");
        info.GetReturnValue().SetUndefined();
        return;
    }
    auto q = new NativeQueue::Queue();
    q->Wrap(info.This());
}

bool NativeQueue::Queue::isEmpty() {
    return _head == NULL;
}

NAN_METHOD(NativeQueue::Queue::Enqueue) {
    // TODO: Check params
    auto q = Nan::ObjectWrap::Unwrap<NativeQueue::Queue>(info.Holder());
    auto n = info[0]->IntegerValue();
    NativeQueue::node *newNode = new node;
    newNode->data = n;
    newNode->next = nullptr;
    if (q->isEmpty()) {
        q->_head = newNode;
        q->_tail = newNode;
    } else {
        // move node down queue
        NativeQueue::node *oldTail = q->_tail;
        q->_tail = newNode;
        oldTail->next = q->_tail;
    }
}

NAN_METHOD(NativeQueue::Queue::Dequeue) {
    auto q = Nan::ObjectWrap::Unwrap<Queue>(info.Holder());
    if (q->isEmpty()) {
        // warn empty queue
        info.GetReturnValue().Set(Nan::New(-1));
        return Nan::ThrowError("the `Queue` is empty!");
    }
    // remove head and get data
    NativeQueue::node *oldHead = q->_head;
    int val = oldHead->data;
    // move node up queue
    q->_head = q->_head->next;
    delete oldHead;
    info.GetReturnValue().Set(val);
}

NAN_METHOD(NativeQueue::Queue::Peek) {
    auto q = Nan::ObjectWrap::Unwrap<NativeQueue::Queue>(info.Holder());
    if (q->isEmpty()) {
        // warn empty queue
        info.GetReturnValue().Set(Nan::New(-1));
        return Nan::ThrowError("the `Queue` is empty!");
    }
    info.GetReturnValue().Set(Nan::New(q->_head->data));
}

NAN_MODULE_INIT(NativeQueue::Queue::Init) {
    auto cname = Nan::New("Queue").ToLocalChecked();
    auto ctor = Nan::New<v8::FunctionTemplate>(New);
    auto ctorInst = ctor->InstanceTemplate();
    ctor->SetClassName(cname);
    ctorInst->SetInternalFieldCount(1);
    
    // add member functions
    Nan::SetPrototypeMethod(ctor, "enqueue", Enqueue);
    Nan::SetPrototypeMethod(ctor, "dequeue", Dequeue);
    Nan::SetPrototypeMethod(ctor, "peek", Peek);
    
    Nan::Set(target, cname, Nan::GetFunction(ctor).ToLocalChecked());
}

