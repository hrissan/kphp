// Compiler for PHP (aka KPHP)
// Copyright (c) 2023 LLC «V Kontakte»
// Distributed under the GPL v3 License, see LICENSE.notice.txt

#include "runtime/tl/tl_func_base.h"

class_instance<C$VK$TL$RpcFunctionReturnResult> f$RpcFunctionFetcher$$typedFetch(class_instance<C$RpcFunctionFetcher> const &v$this) noexcept;

struct tl_func_base_simple_wrapper : public tl_func_base {
  explicit tl_func_base_simple_wrapper(class_instance<C$RpcFunctionFetcher> && wrapped):wrapped_(std::move(wrapped)) {}

  virtual mixed fetch() {
    // all functions annotated with @kphp will override this method with the generated code
    php_critical_error("hrissan TODO: This function should never be called. Should be overridden in every @kphp TL function");
    return mixed{};
  }

  virtual class_instance<C$VK$TL$RpcFunctionReturnResult> typed_fetch() {
    return f$RpcFunctionFetcher$$typedFetch(wrapped_);
  }

  virtual void rpc_server_typed_store(const class_instance<C$VK$TL$RpcFunctionReturnResult>&) {
    // all functions annotated with @kphp will override this method with the generated code
    php_critical_error("hrissan TODO: This function should never be called. Should be overridden in every @kphp TL function");
  }

private:
  class_instance<C$RpcFunctionFetcher> wrapped_;
};

std::unique_ptr<tl_func_base> make_tl_func_base_simple_wrapper(class_instance<C$RpcFunctionFetcher> && custom_fetcher) {
  return std::make_unique<tl_func_base_simple_wrapper>(std::move(custom_fetcher));
}