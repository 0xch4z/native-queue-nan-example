<h2 align="center">Native Queue Example</h2>
<p align="center">A C++ queue abstraction for nodejs</p>

### API Usage

[![Greenkeeper badge](https://badges.greenkeeper.io/Charliekenney23/native-queue-nan-example.svg)](https://greenkeeper.io/)

```js
Queue.prototype.enqueue(n)
```
Pushes an integer `n` to the back of the queue. 
```js
Queue.prototype.dequeue();
```
Pops head from the queue and returns its value.
```js
Queue.prototype.peek();
```
Returns head's value without popping it from the queue.

### Example
```js
const Queue = require('native-queue-nan');

const q = new Queue();

q.enqueue(5);

q.dequeue();
// => 5
```