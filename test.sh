cd $dir; $Temp = (Get-FileHash -Algorithm MD5 $fileName).Hash; if (!$LastOk -or ($Temp -ne $filehash)) {$LastOk = 0; $filehash = $Temp; g++ $fileName -o $fileNameWithoutExt; $LastOk = $?;} if ($LastOk) {echo ("=" * 50); ./$fileNameWithoutExt; echo ("`n" + "=" * 50);}