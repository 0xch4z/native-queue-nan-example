import test from 'ava';
import Queue from './';

test('Throws error when empty', t => {
  const q = new Queue();
  t.throws(() => { q.dequeue() });
});

test('Works', t => {
  const q = new Queue(); 
  for (let i = 3; i; --i) {
    q.enqueue(i);
  }
  for (let i = 3; i; --i) {
    const r = q.dequeue();
    t.is(r, i);
  }
});
