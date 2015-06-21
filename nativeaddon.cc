
#include <nan.h>
#include "library.h"

using namespace v8;

// extern int add(int one, int two);

NAN_METHOD(Add) {
  NanScope();
  Local<Number> lone = args[0].As<Number>();
  Local<Number> ltwo = args[1].As<Number>();
  int one = lone->Int32Value();
  int two = ltwo->Int32Value();
  // int result = add(one, two);
  int result = one + two;
  Local<Number> r = NanNew<Number>(result);
  NanReturnValue(r);
}

void Init(Handle<Object> exports) {
  exports->Set(NanNew("add"), NanNew<FunctionTemplate>(Add)->GetFunction());
}

NODE_MODULE(nativeaddon, Init);
