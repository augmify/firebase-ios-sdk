/*
 * Copyright 2017 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>

@class FIRPhoneAuthCredential;

NS_ASSUME_NONNULL_BEGIN

/** @class FIRAuthErrorUtils
    @brief Utility class used to construct @c NSError instances.
 */
@interface FIRAuthErrorUtils : NSObject

/** @fn RPCRequestEncodingErrorWithUnderlyingError
    @brief Constructs an @c NSError with the @c FIRAuthInternalErrorCodeRPCRequestEncodingError
        code and a populated @c NSUnderlyingErrorKey in the @c NSError.userInfo dictionary.
    @param underlyingError The value of the @c NSUnderlyingErrorKey key.
    @remarks This error is used when an @c FIRAuthRPCRequest.unencodedHTTPRequestBodyWithError:
        invocation returns an error. The error returned is wrapped in this internal error code.
 */
+ (NSError *)RPCRequestEncodingErrorWithUnderlyingError:(NSError *)underlyingError;

/** @fn JSONSerializationErrorForUnencodableType
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeJSONSerializationError code.
    @remarks This error is used when an @c NSJSONSerialization.isValidJSONObject: check fails, not
        for when an error is returned from @c NSJSONSerialization.dataWithJSONObject:options:error:.
 */
+ (NSError *)JSONSerializationErrorForUnencodableType;

/** @fn JSONSerializationErrorWithUnderlyingError:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeJSONSerializationError code, and the
        @c underlyingError as the @c NSUnderlyingErrorKey value in the @c NSError.userInfo
        dictionary.
    @param underlyingError The value of the @c NSUnderlyingErrorKey key.
    @remarks This error is used when an invocation of
        @c NSJSONSerialization.dataWithJSONObject:options:error: returns an error.
 */
+ (NSError *)JSONSerializationErrorWithUnderlyingError:(NSError *)underlyingError;

/** @fn networkErrorWithUnderlyingError:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeNetworkError code, and the
        @c underlyingError as the @c NSUnderlyingErrorKey value in the @c NSError.userInfo
        dictionary.
    @param underlyingError The value of the @c NSUnderlyingErrorKey key. Should be the error from
        GTM.
    @remarks This error is used when a network request results in an error, and no body data was
        returned.
 */
+ (NSError *)networkErrorWithUnderlyingError:(NSError *)underlyingError;

/** @fn unexpectedErrorResponseWithUnderlyingError:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeNetworkError code, and the
        @c underlyingError as the @c NSUnderlyingErrorKey value.
    @param data The value of the @c FIRAuthErrorUserInfoDataKey key in the @c NSError.userInfo
        dictionary.
    @param underlyingError The value of the @c NSUnderlyingErrorKey key in the @c NSError.userInfo
        dictionary.
    @remarks This error is used when a network request results in an error, and unserializable body
        data was returned.
 */
+ (NSError *)unexpectedErrorResponseWithData:(NSData *)data
                             underlyingError:(NSError *)underlyingError;

/** @fn unexpectedErrorResponseWithDeserializedResponse:
    @brief Constructs an @c NSError with the @c FIRAuthInternalErrorCodeUnexpectedErrorResponse
        code, and a populated @c FIRAuthErrorUserInfoDeserializedResponseKey key in the
        @c NSError.userInfo dictionary.
    @param deserializedResponse The value of the @c FIRAuthErrorUserInfoDeserializedResponseKey key.
    @remarks This error is used when a network request results in an error, and the body data was
        deserializable as JSON, but couldn't be decoded as an error.
 */
+ (NSError *)unexpectedErrorResponseWithDeserializedResponse:(id)deserializedResponse;

/** @fn unexpectedResponseWithData:underlyingError:
    @brief Constructs an @c NSError with the @c FIRAuthInternalErrorCodeUnexpectedResponse
        code, and a populated @c FIRAuthErrorUserInfoDataKey key in the @c NSError.userInfo
        dictionary.
    @param data The value of the @c FIRAuthErrorUserInfoDataKey key in the @c NSError.userInfo
        dictionary.
    @param underlyingError The value of the @c NSUnderlyingErrorKey key in the @c NSError.userInfo
        dictionary.
    @remarks This error is used when a network request is apparently successful, but the body data
        couldn't be deserialized as JSON.
 */
+ (NSError *)unexpectedResponseWithData:(NSData *)data
                        underlyingError:(NSError *)underlyingError;;

/** @fn unexpectedResponseWithDeserializedResponse:
    @brief Constructs an @c NSError with the @c FIRAuthInternalErrorCodeUnexpectedResponse
        code, and a populated @c FIRAuthErrorUserInfoDeserializedResponseKey key in the
        @c NSError.userInfo dictionary.
    @param deserializedResponse The value of the @c FIRAuthErrorUserInfoDeserializedResponseKey key.
    @remarks This error is used when a network request is apparently successful, the body data was
        successfully deserialized as JSON, but the JSON wasn't a dictionary.
 */
+ (NSError *)unexpectedResponseWithDeserializedResponse:(id)deserializedResponse;

/** @fn unexpectedResponseWithDeserializedResponse:underlyingError:
    @brief Constructs an @c NSError with the @c FIRAuthInternalErrorCodeUnexpectedResponse
        code, and populated @c FIRAuthErrorUserInfoDeserializedResponseKey and
        @c NSUnderlyingErrorKey keys in the @c NSError.userInfo dictionary.
    @param deserializedResponse The value of the @c FIRAuthErrorUserInfoDeserializedResponseKey key.
    @param underlyingError The value of the @c NSUnderlyingErrorKey key.
    @remarks This error is used when a network request was apparently successful, the body data was
        successfully deserialized as JSON, but the data type of the response was unexpected.
 */
+ (NSError *)unexpectedResponseWithDeserializedResponse:(nullable id)deserializedResponse
                                        underlyingError:(NSError *)underlyingError;

/** @fn RPCResponseDecodingErrorWithDeserializedResponse:underlyingError:
    @brief Constructs an @c NSError with the @c FIRAuthInternalErrorCodeRPCResponseDecodingError
        code, and populated @c FIRAuthErrorUserInfoDeserializedResponseKey and
        @c NSUnderlyingErrorKey keys in the @c NSError.userInfo dictionary.
    @param deserializedResponse The value of the @c FIRAuthErrorUserInfoDeserializedResponseKey key.
    @param underlyingError The value of the @c NSUnderlyingErrorKey key.
    @remarks This error is used when an invocation of @c FIRAuthRPCResponse.setWithDictionary:error:
        resulted in an error.
 */
+ (NSError *)RPCResponseDecodingErrorWithDeserializedResponse:(id)deserializedResponse
                                              underlyingError:(NSError *)underlyingError;

/** @fn emailAlreadyInUseErrorWithEmail:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeEmailExists code.
    @param email The email address that is already in use.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)emailAlreadyInUseErrorWithEmail:(nullable NSString *)email;

/** @fn userDisabledErrorWithMessageWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeUserDisabled code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)userDisabledErrorWithMessage:(nullable NSString *)message;

/** @fn wrongPasswordErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeWrongPassword code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)wrongPasswordErrorWithMessage:(nullable NSString *)message;

/** @fn tooManyRequestsErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeTooManyRequests Code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)tooManyRequestsErrorWithMessage:(nullable NSString *)message;

/** @fn invalidCustomTokenErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeInvalidCustomToken code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidCustomTokenErrorWithMessage:(nullable NSString *)message;

/** @fn customTokenMistmatchErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeCustomTokenMismatch code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)customTokenMistmatchErrorWithMessage:(nullable NSString *)message;

/** @fn invalidCredentialErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeInvalidCredential code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidCredentialErrorWithMessage:(nullable NSString *)message;

/** @fn requiresRecentLoginError
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeRequiresRecentLogin code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)requiresRecentLoginErrorWithMessage:(nullable NSString *)message;

/** @fn invalidUserTokenErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeInvalidUserToken code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidUserTokenErrorWithMessage:(nullable NSString *)message;

/** @fn invalidEmailErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeInvalidEmail code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidEmailErrorWithMessage:(nullable NSString *)message;

/** @fn accountExistsWithDifferentCredentialErrorWithEmail:
    @brief Constructs an @c NSError with the @c FIRAuthErrorAccountExistsWithDifferentCredential
        code.
    @param Email The email address that is already associated with an existing account
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)accountExistsWithDifferentCredentialErrorWithEmail:(nullable NSString *)Email;

/** @fn providerAlreadyLinkedErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeProviderAlreadyLinked code.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)providerAlreadyLinkedError;

/** @fn noSuchProviderError
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeNoSuchProvider code.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)noSuchProviderError;

/** @fn userTokenExpiredErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeUserTokenExpired code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)userTokenExpiredErrorWithMessage:(nullable NSString *)message;

/** @fn userNotFoundErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeUserNotFound code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)userNotFoundErrorWithMessage:(nullable NSString *)message;

/** @fn invalidLocalAPIKeyErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeInvalidAPIKey code.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidAPIKeyError;

/** @fn userMismatchError
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeUserMismatch code.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)userMismatchError;

/** @fn credentialAlreadyInUseErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeCredentialAlreadyInUse code.
    @param message Error message from the backend, if any.
    @param credential Auth credential to be added to the Error User Info dictionary.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)credentialAlreadyInUseErrorWithMessage:(nullable NSString *)message
                                         credential:(nullable FIRPhoneAuthCredential *)credential;

/** @fn operationNotAllowedErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeOperationNotAllowed code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)operationNotAllowedErrorWithMessage:(nullable NSString *)message;

/** @fn weakPasswordErrorWithServerResponseReason:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeWeakPassword code.
    @param serverResponseReason A more detailed explanation string from server response.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)weakPasswordErrorWithServerResponseReason:(NSString *)serverResponseReason;

/** @fn appNotAuthorizedError
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeAppNotAuthorized code.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)appNotAuthorizedError;

/** @fn expiredActionCodeErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeExpiredActionCode code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)expiredActionCodeErrorWithMessage:(nullable NSString *)message;

/** @fn invalidActionCodeErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeInvalidActionCode code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidActionCodeErrorWithMessage:(nullable NSString *)message;

/** @fn invalidMessagePayloadError:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeInvalidMessagePayload code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidMessagePayloadErrorWithMessage:(nullable NSString *)message;

/** @fn invalidSenderErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeInvalidSender code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidSenderErrorWithMessage:(nullable NSString *)message;

/** @fn invalidRecipientEmailError:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeInvalidRecipientEmail code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidRecipientEmailErrorWithMessage:(nullable NSString *)message;

/** @fn missingPhoneNumberErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeMissingPhoneNumber code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)missingPhoneNumberErrorWithMessage:(nullable NSString *)message;

/** @fn invalidPhoneNumberErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeInvalidPhoneNumber code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidPhoneNumberErrorWithMessage:(nullable NSString *)message;

/** @fn missingVerificationCodeErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeMissingVerificationCode code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)missingVerificationCodeErrorWithMessage:(nullable NSString *)message;

/** @fn invalidVerificationCodeErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeInvalidVerificationCode code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidVerificationCodeErrorWithMessage:(nullable NSString *)message;

/** @fn missingVerificationIDErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeMissingVerificationID code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)missingVerificationIDErrorWithMessage:(nullable NSString *)message;

/** @fn invalidVerificationIDErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeInvalidVerificationID code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidVerificationIDErrorWithMessage:(nullable NSString *)message;

/** @fn sessionExpiredErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeSessionExpired code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)sessionExpiredErrorWithMessage:(nullable NSString *)message;

/** @fn missingAppCredentialWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorMissingCredential code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)missingAppCredentialWithMessage:(nullable NSString *)message;

/** @fn invalidAppCredentialWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorInvalidCredential code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)invalidAppCredentialWithMessage:(nullable NSString *)message;

/** @fn quotaExceededErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeQuotaExceeded code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)quotaExceededErrorWithMessage:(nullable NSString *)message;

/** @fn missingAppTokenError
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeMissingAppToken code.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)missingAppTokenError;

/** @fn notificationNotForwardedError
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeNotificationNotForwarded code.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)notificationNotForwardedError;

/** @fn appNotVerifiedErrorWithMessage:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeAppNotVerified code.
    @param message Error message from the backend, if any.
    @return The NSError instance associated with the given FIRAuthError.
 */
+ (NSError *)appNotVerifiedErrorWithMessage:(nullable NSString *)message;

/** @fn keychainErrorWithFunction:status:
    @brief Constructs an @c NSError with the @c FIRAuthErrorCodeKeychainError code.
    @param keychainFunction The keychain function which was invoked and yielded an unexpected
        response. The @c NSLocalizedFailureReasonErrorKey field in the @c NSError.userInfo
        dictionary will contain a string partially comprised of this value.
    @param status The response status from the invoked keychain function. The
        @c NSLocalizedFailureReasonErrorKey field in the @c NSError.userInfo dictionary will contain
        a string partially comprised of this value.
 */
+ (NSError *)keychainErrorWithFunction:(NSString *)keychainFunction status:(OSStatus)status;

@end

NS_ASSUME_NONNULL_END
