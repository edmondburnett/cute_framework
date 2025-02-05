[](../header.md ':include')

# cf_update_time

Category: [time](/api_reference?id=time)  
GitHub: [cute_time.h](https://github.com/RandyGaul/cute_framework/blob/master/include/cute_time.h)  
---

Updates the application.

```cpp
void cf_update_time(CF_OnUpdateFn* on_update);
```

Parameters | Description
--- | ---
on_update | Can be `NULL`. Called once per update. Mostly just useful for the fixed-timestep case (see [cf_set_fixed_timestep](/time/cf_set_fixed_timestep.md)).

## Related Pages

[cf_set_fixed_timestep](/time/cf_set_fixed_timestep.md)  
[cf_set_fixed_timestep_max_updates](/time/cf_set_fixed_timestep_max_updates.md)  
[CF_DELTA_TIME_INTERPOLANT](/time/cf_delta_time_interpolant.md)  
[CF_DELTA_TIME_FIXED](/time/cf_delta_time_fixed.md)  
