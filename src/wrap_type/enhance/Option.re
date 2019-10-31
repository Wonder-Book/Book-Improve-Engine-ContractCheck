let unsafeGet = optionData =>
  Contract.requireCheckReturnResult(
    () =>
      Contract.(
        Operators.(
          test(
            Log.buildAssertMessage(
              ~expect={j|data exist(get by getExn)|j},
              ~actual={j|not|j},
            ),
            () =>
            optionData |> assertExist
          )
        )
      ),
    () => optionData |> Js.Option.getExn,
    Debug.getIsDebug(DebugData.getDebugData()),
  );