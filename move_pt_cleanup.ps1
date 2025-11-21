$root = 'e:\Softwares\Microsoft_VS_Code\data\GAO_QUAN'
# include directories starting with P, T or B followed by digits; exclude P10726
Get-ChildItem -Path $root -Directory | Where-Object { $_.Name -match '^[PTB]\d+$' -and $_.Name -ne 'P10726' } | ForEach-Object {
    $d = $_
    Get-ChildItem -Path $d.FullName -File | ForEach-Object {
        $file = $_
        if ($file.Extension -ieq '.cpp') {
            $target = Join-Path -Path $root -ChildPath $file.Name
            if (Test-Path $target) {
                $base = $file.BaseName
                $dirName = $d.Name
                $ext = $file.Extension
                $target = Join-Path -Path $root -ChildPath ("{0}_{1}{2}" -f $base,$dirName,$ext)
                $i = 1
                while (Test-Path $target) {
                    $target = Join-Path -Path $root -ChildPath ("{0}_{1}_{2}{3}" -f $base,$dirName,$i,$ext)
                    $i++
                }
            }
            Move-Item -Path $file.FullName -Destination $target -Force
        } else {
            # remove non-.cpp files in these directories
            Remove-Item -Path $file.FullName -Force -ErrorAction SilentlyContinue
        }
    }
    # remove directory if empty (no files)
    $remaining = Get-ChildItem -Path $d.FullName -Recurse -Force -ErrorAction SilentlyContinue | Where-Object { -not $_.PSIsContainer }
    if (-not $remaining) {
        Remove-Item -Path $d.FullName -Recurse -Force -ErrorAction SilentlyContinue
    }
}
Write-Output "Done moving .cpp files from P*/T*/B* folders and cleaning up non-.cpp files (P10726 excluded)."