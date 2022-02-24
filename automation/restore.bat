SET BACKUP_DIR=H:\ServiceWrapping\rend\backup
SET BACKUP_TEMP=H:\ServiceWrapping\rend\backup_temp
SET SAVED_DIR="H:\SteamGames\steamapps\common\Rend Server\Otherlands\Saved"

rmdir /S/Q %BACKUP_TEMP%
mkdir %BACKUP_TEMP%
rem move backup.zip %BACKUP_TEMP% - will be used when Jenkins drops in a user-supplied backup.zip
copy %BACKUP_DIR%\backup.zip %BACKUP_TEMP%
cd %BACKUP_TEMP%
jar xf backup.zip

xcopy Config %SAVED_DIR%\Config\ /E/H/Y
xcopy SaveGames %SAVED_DIR%\SaveGames\ /E/H/Y