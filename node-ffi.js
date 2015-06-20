
var path   = require('path');
var assert = require('assert');

var FFI = require('ffi');

var rary = FFI.Library(path.join(__dirname, "rust/library"), {
  'add': [ 'int', [ 'int', 'int' ] ],
  'subtract': [ 'int', [ 'int', 'int' ] ],
  'multiply': [ 'int', [ 'int', 'int' ] ],
  'divide': [ 'int', [ 'int', 'int' ] ]
});

assert.equal(rary.add(1, 2), 3);
assert.equal(rary.add(-1, -5), -6);
assert.equal(rary.subtract(10, 5), 5);
assert.equal(rary.multiply(12, 2), 24);
assert.equal(rary.divide(10, 2), 5);

var one = process.argv[2] || 100;
var two = process.argv[3] || 919;

console.log("%d + %d = %d", one, two, rary.add(one, two));
console.log("%d - %d = %d", one, two, rary.subtract(one, two));
console.log("%d * %d = %d", one, two, rary.multiply(one, two));
console.log("%d / %d = %d", one, two, rary.divide(one, two));
