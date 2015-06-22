
var assert = require('assert');

var bindings    = require('bindings');
var nativeaddon = bindings('nativeaddon');

assert.equal(nativeaddon.add(1, 2), 3);
assert.equal(nativeaddon.add(-1, -5), -6);
assert.equal(nativeaddon.subtract(10, 5), 5);
assert.equal(nativeaddon.multiply(12, 2), 24);
assert.equal(nativeaddon.divide(10, 2), 5);

var one = process.argv[2] || 100;
var two = process.argv[3] || 919;

console.log("%d + %d = %d", one, two, nativeaddon.add(one, two));
console.log("%d - %d = %d", one, two, nativeaddon.subtract(one, two));
console.log("%d * %d = %d", one, two, nativeaddon.multiply(one, two));
console.log("%d / %d = %d", one, two, nativeaddon.divide(one, two));
