#include "textedit.h"

#include <QFile>
#include <QFileInfo>
#include <QMimeData>
#include <QImageReader>

bool TextEdit::canInsertFromMimeData(const QMimeData* source) const
{
    return source->hasImage() || source->hasUrls() ||
            QTextEdit::canInsertFromMimeData(source);
}

void TextEdit::insertFromMimeData(const QMimeData* source)
{
    if (source->hasImage())
    {
        static int i = 1;
        QUrl url(QString("dropped_image_%1").arg(i++));
        dropImage(url, qvariant_cast<QImage>(source->imageData()));
    }
    else if (source->hasUrls())
    {
        foreach (QUrl url, source->urls())
        {
            QFileInfo info(url.toLocalFile());
            if (QImageReader::supportedImageFormats().contains(info.suffix().toLower().toLatin1()))
                dropImage(url, QImage(info.filePath()));
            else
                dropTextFile(url);
        }
    }
    else
    {
        QTextEdit::insertFromMimeData(source);
    }
}

void TextEdit::dropImage(const QUrl& url, const QImage& image)
{
    if (!image.isNull())
    {
        textCursor().insertImage(image);
    }
}

void TextEdit::dropTextFile(const QUrl& url)
{
    QFile file(url.toLocalFile());
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        textCursor().insertText(file.readAll());
}

