[](../header.md ':include')

# cf_make_easy_sprite

Category: [sprite](/api_reference?id=sprite)  
GitHub: [cute_sprite.h](https://github.com/RandyGaul/cute_framework/blob/master/include/cute_sprite.h)  
---

Loads a single-frame sprite from a single png file.

```cpp
CF_Sprite cf_make_easy_sprite(const char* png_path);
```

Parameters | Description
--- | ---
png_path | Virtual path to the .png file.

## Return Value

Returns a [CF_Sprite](/sprite/cf_sprite.md) that can be drawn with `cf_sprite_draw`. The sprite is not animated,
as it's only a single-frame made from a png file.

## Remarks

The preferred way to make a sprite is [cf_make_sprite](/sprite/cf_make_sprite.md), but this function provides a very simple way to get started
by merely loading a single .png image, or for games that don't require animations. See [Virtual File System](https://randygaul.github.io/cute_framework/#/topics/virtual_file_system).

## Related Pages

[CF_Sprite](/sprite/cf_sprite.md)  
[cf_make_sprite](/sprite/cf_make_sprite.md)  
