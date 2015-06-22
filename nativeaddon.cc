
#include <nan.h>

namespace rust {
  extern "C" {
    int add(int one, int two);
  }
}

using namespace v8;

NAN_METHOD(Add) {
  NanScope();
  Local<Number> lone = args[0].As<Number>();
  Local<Number> ltwo = args[1].As<Number>();
  int one = lone->Int32Value();
  int two = ltwo->Int32Value();
  int result = rust::add(one, two);
  Local<Number> r = NanNew<Number>(result);
  NanReturnValue(r);
}

void Init(Handle<Object> exports) {
  exports->Set(NanNew("add"), NanNew<FunctionTemplate>(Add)->GetFunction());
}

NODE_MODULE(nativeaddon, Init);
