[](../header.md ':include')

# cf_entity_add_component

Category: [ecs](/api_reference?id=ecs)  
GitHub: [cute_ecs.h](https://github.com/RandyGaul/cute_framework/blob/master/include/cute_ecs.h)  
---

Adds a component to the new entity definition.

```cpp
void cf_entity_add_component(const char* component_type);
```

Parameters | Description
--- | ---
component_type | The type of component to add.

## Remarks

You must first call [cf_entity_begin](/ecs/cf_entity_begin.md) to begin a new entity definition. `component_type` is a component
defined by [cf_component_begin](/ecs/cf_component_begin.md) and friends.

## Related Pages

[CF_Entity](/ecs/cf_entity.md)  
[cf_entity_begin](/ecs/cf_entity_begin.md)  
[cf_entity_set_name](/ecs/cf_entity_set_name.md)  
[cf_component_begin](/ecs/cf_component_begin.md)  
[cf_entity_end](/ecs/cf_entity_end.md)  
[cf_make_entity](/ecs/cf_make_entity.md)  
