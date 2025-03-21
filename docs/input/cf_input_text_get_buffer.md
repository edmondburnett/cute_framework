[//]: # (This file is automatically generated by Cute Framework's docs parser.)
[//]: # (Do not edit this file by hand!)
[//]: # (See: https://github.com/RandyGaul/cute_framework/blob/master/samples/docs_parser.cpp)
[](../header.md ':include')

# cf_input_text_get_buffer

Category: [input](/api_reference?id=input)  
GitHub: [cute_input.h](https://github.com/RandyGaul/cute_framework/blob/master/include/cute_input.h)  
---

Returns the content of the text input buffer.

```cpp
bool cf_input_text_get_buffer(CF_InputTextBuffer* buffer);
```

## Return Value

Returns true if the input buffer of the application has any text within.

## Remarks

The input text functions are for dealing with text input. Not all text inputs come from a single key-stroke, as some are comprised of
multiple keystrokes, especially when dealing with non-Latin based inputs.

## Related Pages

[cf_input_enable_ime](/input/cf_input_enable_ime.md)  
[cf_input_disable_ime](/input/cf_input_disable_ime.md)  
[cf_input_text_clear](/input/cf_input_text_clear.md)  
