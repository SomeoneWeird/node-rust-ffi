
#include <nan.h>

namespace rust {
  extern "C" {
    int add(int one, int two);
    int subtract(int one, int two);
    int multiply(int one, int two);
    int divide(int one, int two);
  }
}

using namespace v8;

NAN_METHOD(Add) {
  NanScope();
  Local<Number> one = args[0].As<Number>();
  Local<Number> two = args[1].As<Number>();
  int result = rust::add(one->Int32Value(), two->Int32Value());
  Local<Number> r = NanNew<Number>(result);
  NanReturnValue(r);
}

NAN_METHOD(Subtract) {
  NanScope();
  Local<Number> one = args[0].As<Number>();
  Local<Number> two = args[1].As<Number>();
  int result = rust::subtract(one->Int32Value(), two->Int32Value());
  Local<Number> r = NanNew<Number>(result);
  NanReturnValue(r);
}

NAN_METHOD(Multiply) {
  NanScope();
  Local<Number> one = args[0].As<Number>();
  Local<Number> two = args[1].As<Number>();
  int result = rust::multiply(one->Int32Value(), two->Int32Value());
  Local<Number> r = NanNew<Number>(result);
  NanReturnValue(r);
}

NAN_METHOD(Divide) {
  NanScope();
  Local<Number> one = args[0].As<Number>();
  Local<Number> two = args[1].As<Number>();
  int result = rust::divide(one->Int32Value(), two->Int32Value());
  Local<Number> r = NanNew<Number>(result);
  NanReturnValue(r);
}

void Init(Handle<Object> exports) {
  exports->Set(NanNew("add"), NanNew<FunctionTemplate>(Add)->GetFunction());
  exports->Set(NanNew("subtract"), NanNew<FunctionTemplate>(Subtract)->GetFunction());
  exports->Set(NanNew("multiply"), NanNew<FunctionTemplate>(Multiply)->GetFunction());
  exports->Set(NanNew("divide"), NanNew<FunctionTemplate>(Divide)->GetFunction());
}

NODE_MODULE(nativeaddon, Init);
