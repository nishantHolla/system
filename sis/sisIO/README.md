
# SisIO class

Arguments

- const String& **\_logPath** : path of file to log. Can be empty string if not logging anyting.

## mType

Enum of type of messages recognized by the library.

- **mTypeNone** : the message has no type
- **mTypeOkay** : the message is a success message
- **mTypeInfo** : the message contains information to the user
- **mTypeWarn** : the message is a warning to the user
- **mTypeError** : the message reports an error

## output

Output text to the console

### Arguments

- mType **\_mType** : type of the message
- const String& **\_message** : message to output
- bool **\_color** : whether to color the output
- bool **\_tag** : whether to add a tag for the type of message in the output

### Return

None

### input

Template function to get input from the user

### Arguments

- typename **T** : return type of the function
- const String& **\_message** : prompt the user with a message
- bool **\_color** : whether to color the output
- bool **\_tag** : whether to add a tag for the type of message in the output

### Return

- type **T**

## log

Log information to a file

### Arguments

- mType **\_mType** : type of the message
- const String& **\_message** : message to log
- const String& **\_sender** : sender of the log message
