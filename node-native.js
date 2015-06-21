
var assert = require('assert');

var bindings    = require('bindings');
var nativeaddon = bindings('nativeaddon');

assert.equal(nativeaddon.add(1, 2), 3);
assert.equal(nativeaddon.add(-1, -5), -6);

var one = process.argv[2] || 100;
var two = process.argv[3] || 919;

console.log("%d + %d = %d", one, two, nativeaddon.add(one, two));
