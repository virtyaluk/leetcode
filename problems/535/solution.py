class Codec:

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        s = ''

        for ch in longUrl:
            s += str(ord(ch)) + '-'
        
        return s
        

    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        
        return ''.join(map(lambda n: chr(int(n)) if n else '', shortUrl.split('-')))
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))