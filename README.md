Sobre o programa:
O programa é dividido em 3 telas principais:
1. Tela de Login: O programa permite entrar como dois tipos de
usuários, sendo 0 para funcionário, responsável por se cadastrar e
registrar suas horas extras e o gestor, responsável por aprovar as
horas extras e imprimir um relatório final em um arquivo .txt.
<img width="531" height="96" alt="image" src="https://github.com/user-attachments/assets/03b838ce-fd07-42c3-a11f-4f6236c20b82" />

2. Caso o usuário entre com 0 o programa exibira 2 opções, cadastrar funcionário e
registrar horas extras.
<img width="246" height="34" alt="image" src="https://github.com/user-attachments/assets/fa4754ad-8a44-4138-8448-2a355dc346c8" />

Escolhendo 1 o funcionário devera fornecer o seu nome, as horas, valor por hora
e a data. Podendo ter a escolha de registrar outro funcionário.

<img width="541" height="152" alt="image" src="https://github.com/user-attachments/assets/21ecd1fb-0074-4d23-aae7-4d1327a5dd8c" />

Escolhendo 2 o funcionário deve fornecer um ID de um funcionário e registrar
suas novas horas extras.

<img width="354" height="113" alt="image" src="https://github.com/user-attachments/assets/0a296334-69b6-42e0-9589-12e9f159d913" />


3. Caso escolha entrar como gestor o programa ira pedir para inserir um nome de
usuário junto com uma senha. (usuário: gestor | senha: gestor)

<img width="494" height="207" alt="image" src="https://github.com/user-attachments/assets/2a6d8ff1-da9d-468e-bfb0-f7e0b9d96489" />

O gestor pode listar todos funcionários registrados no programa (Opção 1)

<img width="820" height="64" alt="image" src="https://github.com/user-attachments/assets/84930c6b-2964-4697-a05d-1acf015d9660" />

O gestor pode aprovar/reprovar as horas extras (Opção 2)

<img width="532" height="177" alt="image" src="https://github.com/user-attachments/assets/b5beffe5-9b73-4282-a142-9e78fa86a38c" />

Aviso: A aprovação só pode ocorrer antes das 14 horas.
O gestor pode gerar um relatório ao final, exibindo todas as informações em um
arquivo .txt.(Opção 3).

<img width="1273" height="41" alt="image" src="https://github.com/user-attachments/assets/16663ba6-3f64-4e68-b9e0-e4bf6981f53e" />

Escolhendo 0 o programa ira retornar a tela inicial.



===================================================================


Projeto Integrador: Sistema Digital de Controle de Horas Extras – Parceria com a Startup Base27


Introdução

Este projeto integrador está sendo desenvolvido em parceria com a startup Base27, com o objetivo de criar um sistema digital para controle de horas extras. A proposta busca substituir os processos manuais ainda utilizados por muitas empresas, automatizando etapas como o registro, a validação e a aprovação das horas trabalhadas além da jornada.


O sistema será prototipado em Linguagem C pelos alunos de Engenharia da Computação e pelos estudantes do 2º período do curso de Ciência da Computação, com foco na lógica e no funcionamento interno da aplicação.
Simultaneamente, os alunos do 1º período de Ciência da Computação serão responsáveis pelo desenvolvimento da versão web do sistema, com ênfase na interface e na experiência do usuário (UI/UX).
Já os alunos de Engenharia de Software atuarão na documentação técnica e na especificação dos requisitos do sistema, assegurando a consistência, rastreabilidade e qualidade do projeto como um todo.
Essa integração entre os cursos proporciona um aprendizado prático, interdisciplinar e colaborativo, aproximando os estudantes da realidade do desenvolvimento de sistemas no mercado de tecnologia.


1. Quem (ou o quê) gera esse problema?
O problema é gerado pelo processo manual de controle de horas extras realizado atualmente nas. empresas. Esse processo envolve preenchimento de formulários físicos, validações manuais e aprovações sucessivas, o que o torna lento, suscetível a erros e difícil de acompanhar. A ausência de automação provoca atrasos, retrabalho e ineficiência operacional.

2. O que já sabemos sobre esse problema?
O processo precisa ser encerrado em horários fixos (13h ou 14h), inclusive com antecedência em finais de semana e feriados. Isso gera pressão sobre os encarregados e gestores, que precisam consolidar informações rapidamente para não perder o prazo. A falta de um sistema informatizado faz com que qualquer erro ou atraso se reflita em problemas no cálculo e na aprovação das horas extras

3. O que ainda não sabemos?
Ainda não está definido quais tecnologias e ferramentas digitais são ideais para automatizar todo o fluxo de aprovação e controle. É necessário compreender melhor como integrar o processo automatizado aos sistemas corporativos existentes, garantindo segurança, rastreabilidade e agilidade.

4. Quem sofre com o problema?
Os principais afetados são os encarregados, técnicos e gestores, que enfrentam:

• Sobrecarga de trabalho devido ao processo manual;

• Falta de visibilidade sobre os dados;

• Dificuldade em cumprir prazos de fechamento;

• Necessidade de revisar constantemente as informações para evitar erros.

5. Quais hipóteses já foram pensadas ou testadas?
A principal hipótese é o desenvolvimento de um sistema digital de controle de horas extras, que:

• Permita o registro, cálculo e aprovação das horas feita pelo gestor;

• Gere alertas e notificações eletrônicas;

• Automatize o fluxo de validação e reduza falhas humanas;

• Seja simulado em Linguagem C pelos alunos.
Essa versão inicial servirá como base para futuras evoluções — como versões web e mobile integradas.

6. Quais são os ganhos esperados?
Com o novo sistema, espera-se:

• Aumento da eficiência operacional;

• Redução de erros e retrabalho;

• Maior agilidade e transparência no controle das horas;

• Facilidade na gestão de equipes e aprovações;

• Liberação de tempo para atividades mais estratégicas;

• Desenvolvimento prático de habilidades técnicas e de engenharia de software pelos alunos. 7. Justificativa da Linguagem Utilizada O presente projeto será desenvolvido em Linguagem C, escolhida por sua relevância acadêmica e formativa no contexto da Engenharia da 
Computação. Embora o sistema de controle de horas extras tenha potencial de aplicação no mercado corporativo, a opção pelo uso da Linguagem C tem caráter didático e estratégico, visando consolidar os fundamentos de programação estruturada. Ou seja: C é excelente para 
desenvolver o núcleo lógico ou prototipar a lógica computacional — mas não para a camada de aplicação corporativa que o mercado usa no dia a dia. Essas funcionalidades são mais facilmente implementadas em linguagens modernas como Python, C#, Java ou JavaScript, que possuem bibliotecas e frameworks próprios para aplicações empresariais. Dessa forma, o uso de C neste projeto deve ser entendido como uma etapa inicial de aprendizado e prototipagem lógica, que permitirá aos alunos: • Compreender o funcionamento interno de um sistema; 

• Planejar o fluxo de processamento de dados; 

• Criar algoritmos eficientes e bem estruturados; 

• Preparar-se para evoluir o sistema futuramente em linguagens de alto nível. A versão desenvolvida em C representa, portanto, um protótipo funcional, cujo objetivo principal é demonstrar a viabilidade lógica da solução proposta e fortalecer o domínio técnico dos alunos em fundamentos de programação.

Conclusão técnica: A Linguagem C não é ideal para sistemas comerciais que envolvem interfaces, banco de dados e múltiplos usuários, pois exige muito código manual e não oferece bibliotecas modernas para isso. Embora não seja viável a nível de mercado implantar um sistema completo em Linguagem C, a sua utilização neste projeto é plenamente justificada pelo valor educacional que proporciona, promovendo o desenvolvimento do pensamento lógico, da modularização e da compreensão das estruturas fundamentais da computação — competências essenciais para engenheiros de software e profissionais de tecnologia. 8. Entregas
