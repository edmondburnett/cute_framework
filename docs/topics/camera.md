[](../header.md ':include')

<br>

Make sure to read the [Drawing](https://randygaul.github.io/cute_framework/#/topics/drawing) topic before reading about the camera. The various drawing functions are all drawn relative to a small camera API. The camera can look at a specific position, rotate itself, and also adjust it's view scale. Use the camera draw from different perspectives, such as following along as a player moves, or moving along paths during cut scenes.

## Default Camera

When your app window is first created a default camera is automatically setup for you. It's dimensions are the same as the resolution of the drawable area of the window. For example, if you follow along with the [Getting Started](https://randygaul.github.io/cute_framework/#/getting_started) page the window will have pixel dimensions of 640x480. The camera copies those dimensions and scales itself to a width of 640 and height of 480. You can adjust the camera's scale with [`cf_camera_dimensions`](https://randygaul.github.io/cute_framework/#/camera/cf_camera_dimensions).

```cpp
float screen_w = 640.0f;
float screen_h = 480.0f;

// Zoom the camera in by 2x
cf_camera_dimensions(screen_w * 0.5f, screen_h * 0.5f);
```

?> You can flip the screen on the x-axis by negating the camera width when calling [`cf_camera_dimensions`](https://randygaul.github.io/cute_framework/#/camera/cf_camera_dimensions). You can also flip the screen on the y-axis by negating the second parameter, the camera height.

## Coordinate System

In games typically the center of the screen is defined as position `(0, 0)`, with the positive y-axis going up the screen.

## Moving the Camera

When we move the camera it's look location points to a new position with [`cf_camera_look_at`](https://randygaul.github.io/cute_framework/#/camera/cf_camera_look_at). By default the camera starts out looking at the origin `(0, 0)`. If we make the camera look at `(100, 0)` everything on the screen will shift to the left by `100` units.

Instead you may prefer to "offset the world" instead of the camera. This way, if we offset the world from `(0, 0)` to `(100, 0)` then everything will be drawn 100 units to the right. To apply this technique you can make your own function for offsetting the world.

```cpp
void OffsetWorld(v2 position)
{
	cf_camera_look_at(-position.x, -position.y);
}
```

---

TODO - Add sample here.

## Rotating the Camera

The camera itself can be rotated with [`cf_camera_rotate`](https://randygaul.github.io/cute_framework/#/camera/cf_camera_rotate). A positive parameter will rotate counter-clockwise by a number of radians. This means everything on the screen will appear to rotate counter-clockwise.

## Camera Push and Pop

The camera comes along with [`cf_camera_push`](https://randygaul.github.io/cute_framework/#/camera/cf_camera_push) and [`cf_camera_pop`](https://randygaul.github.io/cute_framework/#/camera/cf_camera_pop). Internally CF has a stack of cameras. Whenever you call push it places a copy of the camera onto the stack. This is great for looking at all the various objects in your game and drawing them at their respective locations. Each time you want to visit a new location you may push the old camera, draw your object, then pop the camera. When popping the previously pushed camera is restored.

This kind of push/pop control is ideal for drawing anything heirarchical, such as parented game objects, enemies around a level, bits of user-interface elements that should move all together, etc.

TODO - Add sample for this.

## Getting the Camera

You may peek at the current camera with [`cf_camera_peek_position`](https://randygaul.github.io/cute_framework/#/camera/cf_camera_peek_position), [`cf_camera_peek_dimensions`](https://randygaul.github.io/cute_framework/#/camera/cf_camera_peek_dimensions), or [`cf_camera_peek_rotation`](https://randygaul.github.io/cute_framework/#/camera/cf_camera_peek_rotation). The values returned are always from the last camera to have been setup by any other camera functions. If [`cf_camera_pop`](https://randygaul.github.io/cute_framework/#/camera/cf_camera_pop) is called the previously used camera will be restored, changing the return values of all the peek functions.
