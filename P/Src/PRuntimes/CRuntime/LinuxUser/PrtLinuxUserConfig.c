#include "PrtLinuxUserConfig.h"
#include "Prt.h"

PRT_RECURSIVE_MUTEX PRT_CALL_CONV PrtCreateMutex()
{
  return NULL;
}

void PRT_CALL_CONV PrtDestroyMutex(_In_ PRT_RECURSIVE_MUTEX mutex)
{
}

void PRT_CALL_CONV PrtLockMutex(_In_ PRT_RECURSIVE_MUTEX mutex)
{
}

void PRT_CALL_CONV PrtUnlockMutex(_In_ PRT_RECURSIVE_MUTEX mutex)
{
}

PRT_API PRT_SEMAPHORE PRT_CALL_CONV PrtCreateSemaphore(int initialCount, int maximumCount)
{
    return NULL;
}

PRT_API void PRT_CALL_CONV PrtDestroySemaphore(_In_ PRT_SEMAPHORE semaphore)
{
}

PRT_API PRT_BOOLEAN PRT_CALL_CONV PrtWaitSemaphore(_In_ PRT_SEMAPHORE semaphore, _In_ long maxWaitTime)
{
    return PRT_TRUE;
}

PRT_API PRT_BOOLEAN PRT_CALL_CONV PrtReleaseSemaphore(_In_ PRT_SEMAPHORE semaphore)
{
    return PRT_TRUE;
}

PRT_API void PRT_CALL_CONV PrtYieldThread()
{
    //sched_yield();
}

void * PRT_CALL_CONV PrtMalloc(_In_ size_t size)
{
  void *ptr = malloc(size);
  return ptr;
}

void * PRT_CALL_CONV PrtCalloc(_In_ size_t nmemb, _In_ size_t size)
{
  //PrtAssert(size > 0, "Size must be positive to avoid platform-specific behavior");
  //PrtAssert(nmemb > 0, "Size must be positive to avoid platform-specific behavior");

  void *ptr = calloc(nmemb, size);
  PrtAssert(ptr != NULL, "Memory allocation error");
  return ptr;
}

void * PRT_CALL_CONV PrtRealloc(_Inout_ void *ptr, _In_ size_t size)
{
  ptr = realloc(ptr, size);
  return ptr;
}

void PRT_CALL_CONV PrtFree(void *ptr)
{
  free(ptr);
}

PRT_BOOLEAN PRT_CALL_CONV PrtChoose()
{
  PRT_UINT32 value = rand();
  if (value < RAND_MAX / 2)
    return PRT_FALSE;
  else
    return PRT_TRUE;
}
