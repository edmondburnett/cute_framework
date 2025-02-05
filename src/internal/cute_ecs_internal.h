/*
	Cute Framework
	Copyright (C) 2023 Randy Gaul https://randygaul.github.io/

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1. The origin of this software must not be misrepresented; you must not
	   claim that you wrote the original software. If you use this software
	   in a product, an acknowledgment in the product documentation would be
	   appreciated but is not required.
	2. Altered source versions must be plainly marked as such, and must not be
	   misrepresented as being the original software.
	3. This notice may not be removed or altered from any source distribution.
*/

#ifndef CF_ECS_INTERNAL_H
#define CF_ECS_INTERNAL_H

#include <cute_string.h>
#include <cute_array.h>
#include <cute_ecs.h>

struct CF_EntityCollection
{
	Cute::HandleTable entity_handle_table;
	Cute::Array<CF_Handle> entity_handles; // TODO - Replace with a counter? Or delete?
	Cute::Array<const char*> component_type_tuple;
	Cute::Array<CF_TypelessArray> component_tables;
	int inactive_count = 0;
};

struct CF_SystemInternal
{
	void clear()
	{
		name = { 0 };
		udata = NULL;
		pre_update_fn = NULL;
		update_fn = NULL;
		post_update_fn = NULL;
		component_type_tuple.clear();
	}

	const char* name = { 0 };
	void* udata = NULL;
	void (*pre_update_fn)(void* udata) = NULL;
	CF_SystemUpdateFn* update_fn = NULL;
	void (*post_update_fn)(void* udata) = NULL;
	Cute::Array<const char*> component_type_tuple;
};

struct CF_ComponentConfig
{
	void clear()
	{
		name = NULL;
		size_of_component = 0;
		initializer = NULL;
		cleanup = NULL;
		initializer_udata = NULL;
		cleanup_udata = NULL;
	}

	const char* name = NULL;
	size_t size_of_component = 0;
	CF_ComponentFn* initializer = NULL;
	CF_ComponentFn* cleanup = NULL;
	void* initializer_udata = NULL;
	void* cleanup_udata = NULL;
};

struct CF_EntityConfig
{
	void clear()
	{
		entity_type = NULL;
		component_types.clear();
	}

	const char* entity_type = NULL;
	Cute::Array<const char*> component_types;
};

using CF_EntityType = uint16_t;
#define CF_INVALID_ENTITY_TYPE ((uint16_t)~0)

struct CF_ComponentListInternal
{
	int count = 0;
	CF_Handle* entities = NULL;
	Cute::Array<const char*> types;
	Cute::Array<CF_TypelessArray>* ptrs;

	void* find_components(const char* type)
	{
		type = sintern(type);
		for (int i = 0; i < count; ++i) {
			if (types[i] == type) {
				return (*ptrs)[i].data();
			}
		}
		return NULL;
	}
};

struct CF_WorldInternal
{
	Cute::Map<CF_EntityType, CF_EntityCollection> entity_collections;
	Cute::Array<CF_Entity> delayed_destroy_entities;
	Cute::Array<CF_Entity> delayed_deactivate_entities;
	Cute::Array<CF_Entity> delayed_activate_entities;
};

#endif // CF_ECS_INTERNAL_H
