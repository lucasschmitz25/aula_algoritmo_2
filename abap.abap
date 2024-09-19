  METHOD is_prime_number.

    DATA: lv_flag TYPE abap_bool VALUE abap_true,
          lv_i    TYPE i,
          calc    TYPE p DECIMALS 2.

* A intenção original disso era testar todos os possíveis divisores de p_num, começando pelo 2 até p_num - 1.
* Ou seja, verificar se o número é divisível por qualquer número menor que ele próprio (exceto 1).
* Se ele for divisível por qualquer número nesse intervalo, então ele não é primo.
    DO number - 1 TIMES.

      lv_i = sy-index + 1. " já que não precisamos testar se o número é divisível por 1 (todo número é divisível por 1, mas isso não significa que ele não seja primo).
      IF lv_i >= number. " Se lv_i for maior ou igual ao número, podemos concluir que o número é primo
        result = abap_true.
        EXIT.
      ENDIF.

      IF number MOD lv_i = 0. " Se number MOD lv_i = 0, significa que number é divisível por lv_i, e, portanto, não é primo.
        result = abap_false.
        EXIT.
      ENDIF.

    ENDDO.

    DO number - 1 TIMES.

      lv_i = sy-index + 1.

      IF lv_i >= number.
        result = abap_true.
        EXIT.
      ENDIF.

      calc = number MOD lv_i.
      IF calc <> 0.
        result = abap_true.
        EXIT.
      ELSE.
        result = abap_false.
        EXIT.
      ENDIF.

    ENDDO.

  ENDMETHOD.
