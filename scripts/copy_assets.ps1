param(
    [Parameter(Mandatory = $true)]
    [string]$Source,

    [Parameter(Mandatory = $true)]
    [string]$Destination
)

if (-not (Test-Path $Source -PathType Container)) {
    Write-Error "Source directory does not exist: $Source"
    exit 1
}

if (-not (Test-Path $Destination)) {
    New-Item -ItemType Directory -Path $Destination -Force | Out-Null
}

robocopy `
    $Source `
    $Destination `
    /E `
    /XO `
    /R:2 `
    /W:2 `
    /NFL `
    /NDL

# 0 = No files copied
# 1 = Files copied successfully
# 2-7 = Success with extra information
# 8+ = Failure
if ($LASTEXITCODE -ge 8) {
    Write-Error "Robocopy failed with exit code $LASTEXITCODE."
    exit $LASTEXITCODE
}

Write-Host "Copy completed successfully."