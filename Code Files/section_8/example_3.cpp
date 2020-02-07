std::exception_ptr exception = nullptr;

if (not a.await_ready())
{
    suspend_coroutine();

    //if await_suspend returns void
    try {
        a.await_suspend(coroutine_handle);
        return_to_the_caller();
    } catch (...) {
        exception = std::current_exception();
        goto resume_point;
    }
    //endif

    //if await_suspend returns bool
    bool await_suspend_result;
    try
    {
        await_suspend_result = a.await_suspend(coroutine_handle);
    }
    catch (...)
    {
        exception = std::current_exception();
        goto resume_point;
    }
    if (not await_suspend_result)
        goto resume_point;
    return_to_the_caller();
    //endif

    //if await_suspend returns another coroutine_handle
    decltype(a.await_suspend(std::declval<coro_handle_t>())) another_coro_handle;
    try
    {
        another_coro_handle = a.await_suspend(coroutine_handle);
    }
    catch (...)
    {
        exception = std::current_exception();
        goto resume_point;
    }
    another_coro_handle.resume();
    return_to_the_caller();
    //endif
}
resume_point:
if(exception)
  std::rethrow_exception(exception);
"return" a.await_resume();
