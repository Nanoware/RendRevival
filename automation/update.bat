SET SAVED_DIR="H:\SteamGames\steamapps\common\Rend Server\Otherlands\Saved"
SET ORIGIN_DIR=H:\ServiceWrapping\rend\git\RendRevival\server-saga

mkdir %SAVED_DIR%
copy /Y %ORIGIN_DIR%\Game.ini %SAVED_DIR%\Config\WindowsServer\
copy /Y %ORIGIN_DIR%\Server.ini %SAVED_DIR%\Config\WindowsServer\
copy /Y %ORIGIN_DIR%\config.ini %SAVED_DIR%\..\..\
