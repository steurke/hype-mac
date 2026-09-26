#pragma once
#include <QFontDatabase>
#include <QString>
#include <QStringList>

// The presentation's default font family. The format was authored on Linux
// around JetBrains Mono; macOS ships different monospaces, so pick one that is
// actually installed. A presentation can still name any family in its header.
inline QString hypeDefaultFontFamily() {
#ifdef Q_OS_MACOS
    const QStringList families = QFontDatabase::families();
    for (const auto &candidate : {QStringLiteral("SF Mono"), QStringLiteral("Menlo"),
                                  QStringLiteral("Monaco")})
        if (families.contains(candidate))
            return candidate;
    return QStringLiteral("Menlo");
#else
    return QStringLiteral("JetBrains Mono");
#endif
}
