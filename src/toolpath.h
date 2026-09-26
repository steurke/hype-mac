#pragma once
#include <QFileInfo>
#include <QStandardPaths>
#include <QString>
#include <QStringList>

// External helpers (ffmpeg, source-highlight) are resolved against PATH, but a
// bundled .app launched from Finder has a minimal PATH that omits Homebrew. Look
// in the usual install prefixes as well. HYPE_<TOOL>_PATH overrides everything.
inline QString hypeToolPath(const QString &name) {
    const QByteArray override = qgetenv("HYPE_" + name.toUpper().toUtf8() + "_PATH");
    if (!override.isEmpty() && QFileInfo(QString::fromLocal8Bit(override)).isExecutable())
        return QString::fromLocal8Bit(override);
    const QString found = QStandardPaths::findExecutable(name);
    if (!found.isEmpty())
        return found;
    for (const auto &dir : {QStringLiteral("/opt/homebrew/bin"), QStringLiteral("/usr/local/bin"),
                            QStringLiteral("/usr/bin"), QStringLiteral("/bin")}) {
        const QString candidate = dir + '/' + name;
        if (QFileInfo(candidate).isExecutable())
            return candidate;
    }
    return name; // Fall back to PATH lookup at exec time.
}
