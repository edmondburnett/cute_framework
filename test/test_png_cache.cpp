/*
	Cute Framework
	Copyright (C) 2024 Randy Gaul https://randygaul.github.io/

	This software is dual-licensed with zlib or Unlicense, check LICENSE.txt for more info
*/

#include "test_harness.h"

#include <cute.h>
using namespace Cute;

#include <internal/cute_png_cache_internal.h>

#include "white_pixel.h"
#include "black_pixel.h"

/* Test all functions of the png caching API. */
TEST_CASE(test_png_cache_all)
{
	cf_fs_init(NULL);
	cf_fs_mount(cf_fs_get_base_directory(), "", true);

	cf_make_png_cache();

	CF_Png white;
	CF_Png black;
	CF_Result err = cf_png_cache_load_from_memory("test_data/white_pixel.png", white_pixel_data, white_pixel_sz, &white);
	REQUIRE(!cf_is_error(err));
	err = cf_png_cache_load_from_memory("test_data/black_pixel.png", black_pixel_data, black_pixel_sz, &black);
	REQUIRE(!cf_is_error(err));

	CF_Png blink_png[] = { white, black };
	float blink_delay[] = { 0.5f, 0.5f };
	
	CF_Png white_png[] = { white };
	float white_delay[] = { 1.0f };

	CF_Png black_png[] = { black };
	float black_delay[] = { 1.0f };

	const CF_Animation* blink_anim = cf_make_png_cache_animation("blink", blink_png, CF_ARRAY_SIZE(blink_png), blink_delay, CF_ARRAY_SIZE(blink_delay));
	const CF_Animation* white_anim = cf_make_png_cache_animation("white", white_png, CF_ARRAY_SIZE(white_png), white_delay, CF_ARRAY_SIZE(white_delay));
	const CF_Animation* black_anim = cf_make_png_cache_animation("black", black_png, CF_ARRAY_SIZE(black_png), black_delay, CF_ARRAY_SIZE(black_delay));

	const CF_Animation* anims[] = { blink_anim, white_anim, black_anim };

	const CF_Animation** table = cf_make_png_cache_animation_table("blink", anims, CF_ARRAY_SIZE(anims));
	CF_Sprite sprite = cf_make_png_cache_sprite("blink", table);

	cf_sprite_play(&sprite, "blink");
	CHECK_POINTER(sprite.animations);
	REQUIRE(sprite.frame_index == 0);

	CF_DELTA_TIME = 0.5f; // Hacky, yes.
	cf_sprite_update(&sprite);
	REQUIRE(sprite.frame_index == 1);

	cf_destroy_png_cache();

	cf_fs_destroy();

	return true;
}

TEST_SUITE(test_png_cache)
{
	RUN_TEST_CASE(test_png_cache_all);
}
