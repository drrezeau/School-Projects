def content_type(filename):
    if filename.contains(".htm") or filename.contains(".html"):
        return "text/html"
    if filename.contains(".gif"):
        return "image/gif"
    if filename.contains(".jpeg") or filename.contains(".jpg"):
        return "image/jpeg"
    if filename.contains(".txt"):
        return "text/plain"
    return "application/octet-stream"
