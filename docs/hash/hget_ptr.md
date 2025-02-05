[](../header.md ':include')

# hget_ptr

Category: [hash](/api_reference?id=hash)  
GitHub: [cute_hashtable.h](https://github.com/RandyGaul/cute_framework/blob/master/include/cute_hashtable.h)  
---

Fetches a pointer to the item that `k` maps to.

```cpp
#define hget_ptr(h, k) cf_hashtable_get_ptr(h, k)
```

Parameters | Description
--- | ---
h | The hashtable. Can be `NULL`. Needs to be a pointer to the type of items in the table.
k | The key for lookups. Each {key, item} pair must be unique. Keys are always typecasted to `uint64_t` e.g. you can use pointers as keys.

## Return Value

Returns a pointer to an item. Returns `NULL` if not found.

## Code Example

> Set and get a few elements from a hashtable.

```cpp
htbl CF_V2 table = NULL;
hadd(table, 10, cf_v2(-1, 1));
CF_V2 v = hget_ptr(table, 10);
CF_ASSERT(v);
CF_ASSERT(v->x == -1);
CF_ASSERT(v->y == 1);
hfree(table);
```

## Remarks

If you want to fetch an item by value, you can use [hget](/hash/hget.md) or [hfind](/hash/hfind.md). Does the same thing as [hfind_ptr](/hash/hfind_ptr.md).

## Related Pages

[htbl](/hash/htbl.md)  
[hset](/hash/hset.md)  
[hadd](/hash/hadd.md)  
[hget](/hash/hget.md)  
[hfind](/hash/hfind.md)  
[hfree](/hash/hfree.md)  
[hfind_ptr](/hash/hfind_ptr.md)  
[hhas](/hash/hhas.md)  
[hdel](/hash/hdel.md)  
[hclear](/hash/hclear.md)  
[hkeys](/hash/hkeys.md)  
[hitems](/hash/hitems.md)  
[hswap](/hash/hswap.md)  
[hsize](/hash/hsize.md)  
[hcount](/hash/hcount.md)  
