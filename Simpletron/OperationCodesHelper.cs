namespace Simpletron;

public static class OperationCodeHelper
{
    public static bool IsValid(this OperationCode operationCode)
    {
        return Enum.IsDefined<OperationCode>(operationCode);
    }
}