class NoAVL:
    def __init__(self, id, data):
        self.id = id
        self.data = data
        self.altura = 1
        self.esquerda = None
        self.direita = None


class ArvoreAVL:
    def __init__(self):
        self.raiz = None

    def inserir(self, id, data):
        self.raiz = self._inserir_no(self.raiz, id, data)

    def _inserir_no(self, no, id, data):
        if not no:
            return NoAVL(id, data)

        if data < no.data:
            no.esquerda = self._inserir_no(no.esquerda, id, data)
        else:
            no.direita = self._inserir_no(no.direita, id, data)

        no.altura = 1 + max(self._obter_altura(no.esquerda), self._obter_altura(no.direita))

        fator_balanceamento = self._obter_fator_balanceamento(no)

        if fator_balanceamento > 1:
            if data < no.esquerda.data:
                return self._rotacionar_direita(no)
            else:
                no.esquerda = self._rotacionar_esquerda(no.esquerda)
                return self._rotacionar_direita(no)

        if fator_balanceamento < -1:
            if data > no.direita.data:
                return self._rotacionar_esquerda(no)
            else:
                no.direita = self._rotacionar_direita(no.direita)
                return self._rotacionar_esquerda(no)

        return no

    def _obter_altura(self, no):
        if not no:
            return 0
        return no.altura

    def _obter_fator_balanceamento(self, no):
        if not no:
            return 0
        return self._obter_altura(no.esquerda) - self._obter_altura(no.direita)

    def _rotacionar_direita(self, z):
        y = z.esquerda
        T3 = y.direita

        y.direita = z
        z.esquerda = T3

        z.altura = 1 + max(self._obter_altura(z.esquerda), self._obter_altura(z.direita))
        y.altura = 1 + max(self._obter_altura(y.esquerda), self._obter_altura(y.direita))

        return y

    def _rotacionar_esquerda(self, z):
        y = z.direita
        T2 = y.esquerda

        y.esquerda = z
        z.direita = T2

        z.altura = 1 + max(self._obter_altura(z.esquerda), self._obter_altura(z.direita))
        y.altura = 1 + max(self._obter_altura(y.esquerda), self._obter_altura(y.direita))

        return y

    def obter_artefato_mais_recente(self):
        if not self.raiz:
            return None
        no = self.raiz
        while no.direita:
            no = no.direita
        return no.id

    def obter_artefato_mais_antigo(self):
        if not self.raiz:
            return None
        no = self.raiz
        while no.esquerda:
            no = no.esquerda
        return no.id


def main():
    arvore = ArvoreAVL()

    # Inserindo alguns artefatos na árvore
    arvore.inserir(1, "2023-06-01")
    arvore.inserir(2, "2023-06-05")
    arvore.inserir(3, "2023-06-02")
    arvore.inserir(4, "2023-06-10")

    # Obtendo o artefato mais recente e mais antigo
    artefato_mais_recente = arvore.obter_artefato_mais_recente()
    artefato_mais_antigo = arvore.obter_artefato_mais_antigo()

    print("Artefato mais recente:", artefato_mais_recente)
    print("Artefato mais antigo:", artefato_mais_antigo)


if __name__ == "__main__":
    main()
