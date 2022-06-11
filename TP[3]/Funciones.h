#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/// @brief -1 ERROR 1 IS DIGIT 0 IS NOT DIGIT
///
/// @param string
/// @return
int IsDigit(char* string);



/// @brief  -1 ERROR 1 IS FLOAT DIGIT 0 IS NOT FLOAT DIGIT
///
/// @param string
/// @return
int IsFloatDigit(char* string);



/// @brief 1 ERROR 1 DOESNT HAVE ANY NUMBER 0 IT HAVE A NUMBER
///
/// @param string
/// @return
int DoesntHaveAnyNumber(char* string);



/// @brief function to set the range of int, -1 ERROR 1 SUCCESS
///
/// @param number
/// @param min
/// @param max
/// @param message
/// @param messageError
/// @return
int setRangeInt(int* number, int min, int max, char* message, char* messageError);



/// @brief function to set int, -1 ERROR 1 SUCCESS
///
/// @param number
/// @param message
/// @param messageError
/// @return
int setInt(int* number, char* message, char* messageError);



/// @brief function to set the range of tries, -1 ERROR 1 SUCCES 0 NO MORE TRIES
///
/// @param number
/// @param min
/// @param max
/// @param message
/// @param messageError
/// @param tries
/// @return
int setRangeIntTries(int* number, int min, int max, char* message, char* messageError, int tries);



/// @brief function to set float, -1 ERROR 1 SUCCESS
///
/// @param number
/// @param message
/// @param messageError
/// @return
int setFloat(float* number, char* message, char* messageError);



/// @brief function to set the range of float, -1 ERROR 1 SUCCESS
///
/// @param number
/// @param min
/// @param max
/// @param message
/// @param messageError
/// @return
int setFloatRange(float* number, float min, float max, char* message, char* messageError);



/// @brief function to set strings, -1 ERROR 1 SUCCESS
///
/// @param string
/// @param size
/// @param message
/// @param errorMessage
/// @return
int setString(char* string, int size, char* message, char* errorMessage);



/// @brief  function to set strings, -1 ERROR 1 SUCCESS
///
/// @param string
/// @param size
/// @param tries
/// @param message
/// @param errorMessage
/// @return
int setStringTries(char* string, int size, int tries, char* message, char* errorMessage);



/// @brief function to set the name, -1 ERROR 1 SUCCESS
///
/// @param string
/// @param size
/// @param message
/// @param errorMessage
/// @return
int setName(char* string, int size, char* message, char* errorMessage);



/// @brief function to print the result of the actions
///
/// @param number
/// @param actionMessage
void validator(int number, char* actionMessage);



/// @brief function to print the result of the actions with mensaje error
///
/// @param number
/// @param actionMessage
/// @param errorActionMessage
void validatorWithMessageError(int number, char* actionMessage, char* errorActionMessage);

#endif /* FUNCTIONS_H_ */
