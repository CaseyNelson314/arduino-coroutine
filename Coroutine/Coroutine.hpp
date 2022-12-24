/// @file   Coroutine.hpp
/// @brief  擬似コルーチン

#pragma once

/// @brief コルーチンを開始
#define CO_BEGIN \
    [&] {                       \
        static int __state = 0; \
        static int __timer = 0; \
        switch (__state) {      \
        case 0:

/// @brief コルーチンを抜ける。関数再開時に復帰する点を指定
#define CO_YIELD            \
    {                       \
        __state = __LINE__; \
        return;             \
    case __LINE__:          \
        break;              \
    };

/// @brief コルーチン終了、再起動
#define CO_END   \
    __state = 0; \
    }            \
    }            \
    ();

/// @brief 引数の指定期間経過まで処理を通さない
#define CO_DELAY(ms)                 \
    {                                \
        __state = __LINE__;          \
        __timer = millis();          \
        return;                      \
    case __LINE__:                   \
        if (millis() - __timer < ms) \
            return;                  \
    };

/// @brief 引数がtrueになるまで処理を通さない
#define CO_AWAIT(flag)      \
    {                       \
        __state = __LINE__; \
        return;             \
    case __LINE__:          \
        if (not flag)       \
            return;         \
    };
