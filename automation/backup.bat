SET SAVED_DIR="H:\SteamGames\steamapps\common\Rend Server\Otherlands\Saved"
SET BACKUP_DIR=H:\ServiceWrapping\rend\backup

rmdir /S/Q %BACKUP_DIR%
cd %SAVED_DIR%
xcopy Config %BACKUP_DIR%\Config\ /E/H
mkdir %BACKUP_DIR%\SaveGames\
copy SaveGames\MASTER_JRK.sav %BACKUP_DIR%\SaveGames\MASTER_JRK.sav
copy SaveGames\MASTER_JRK-PREV.sav %BACKUP_DIR%\SaveGames\MASTER_JRK-PREV.sav
copy SaveGames\REND_ETERNAL.sav %BACKUP_DIR%\SaveGames\REND_ETERNAL.sav
copy SaveGames\REND_ETERNAL-PREV.sav %BACKUP_DIR%\SaveGames\REND_ETERNAL-PREV.sav
copy SaveGames\Rend_Persistent.sav %BACKUP_DIR%\SaveGames\Rend_Persistent.sav
copy SaveGames\Rend_Persistent-PREV.sav %BACKUP_DIR%\SaveGames\Rend_Persistent-PREV.sav
cd %BACKUP_DIR%
jar -cfM backup.zip *
