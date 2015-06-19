
var path   = require('path');
var assert = require('assert');

var FFI = require('ffi');

var rary = FFI.Library(path.join(__dirname, "rust/library.dylib"), {
  'add': [ 'int', [ 'int', 'int' ] ]
});

assert.equal(rary.add(1, 2), 3);
assert.equal(rary.add(-1, -5), -6);

var one = process.argv[2] || 100;
var two = process.argv[3] || 919;

console.log("%d + %d = %d", one, two, rary.add(one, two));
